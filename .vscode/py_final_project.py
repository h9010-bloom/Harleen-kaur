import os
from datetime import datetime
import matplotlib.pyplot as plt
from collections import defaultdict

menu = {
    "Drinks": {
        "Espresso": 60,
        "Cappuccino": 80,
        "Latte": 90,
        "Cold Coffee": 100,
        "Green Tea": 50,
        "Masala Chai": 40,
        "Hot Chocolate": 110
    },
    "Food": {
        "Sandwich": 120,
        "Burger": 150,
        "Pasta": 180
    },
    "Desserts": {
        "Brownie": 70,
        "Cheesecake": 130
    }
}

ADMIN_PASSWORD = "cafe123"

total_orders = 0
total_sales = 0


def clear_screen():
    print("\n" * 50)


def print_header():
    print("=" * 50)
    print("      ☕ WELCOME TO SUNSHINE CAFE ☕")
    print("       Your Daily Sip of Happiness")
    print("=" * 50)


def show_menu():
    clear_screen()
    print_header()

    print(f"\n{'No.':<5}{'Item':<20}{'Price'}")
    print("-" * 35)

    item_map = {}
    count = 1

    for category, items in menu.items():
        print(f"\n-- {category} --")
        for item, price in items.items():
            print(f"{count:<5}{item:<20}Rs.{price}")
            item_map[str(count)] = (item, price, category)
            count += 1

    return item_map


def load_today_orders():
    global total_orders, total_sales

    if not os.path.exists("all_orders.txt"):
        return

    today = datetime.now().strftime("%d-%m-%Y")

    with open("all_orders.txt", "r") as f:
        content = f.read().split("=" * 40)

        for block in content:
            if today in block:
                total_orders += 1
                for line in block.split("\n"):
                    if "Total: Rs." in line:
                        total_sales += float(line.split("Rs.")[1])


def place_order():
    global total_orders, total_sales

    clear_screen()
    print_header()

    name = input("Enter Name: ").strip()

    while True:
        phone = input("Enter Phone: ")
        if phone.isdigit() and len(phone) == 10:
            break
        print("Invalid phone number")

    item_map = show_menu()
    order_list = []

    while True:
        choices = input("\nEnter item numbers: ").split()

        for choice in choices:
            if choice not in item_map:
                continue

            item, price, category = item_map[choice]

            if category == "Drinks":
                while True:
                    inp = input(f"Enter quantity and size for {item} (e.g. 2 S / 3 M): ").upper().split()
                    if len(inp) == 2 and inp[0].isdigit() and inp[1] in ["S", "M"]:
                        qty = int(inp[0])
                        size = "Small" if inp[1] == "S" else "Medium"
                        if size == "Medium":
                            price += 20
                        break
                    else:
                        print("Invalid input. Example: 2 S or 3 M")
            else:
                while True:
                    try:
                        qty = int(input(f"Quantity for {item}: "))
                        if qty > 0:
                            size = "-"
                            break
                    except:
                        print("Enter valid number")

            order_list.append((item, size, qty, price))

        more = input("Add more? (y/n): ")
        if more.lower() != 'y':
            break

    clear_screen()
    print_header()

    now = datetime.now().strftime("%d-%m-%Y %I:%M %p")

    print(f"\nName: {name}")
    print(f"Phone: {phone}")
    print(f"Date: {now}")

    grand_total = 0
    for item, size, qty, price in order_list:
        total = qty * price
        grand_total += total
        print(f"{item} ({size}) x{qty} = Rs.{total}")

    gst = grand_total * 0.05
    final = grand_total + gst

    print(f"\nTotal: Rs.{final:.2f}")

    with open("all_orders.txt", "a") as f:
        f.write("\n" + "=" * 40 + "\n")
        f.write(f"Date: {now}\n")
        f.write(f"Name: {name}\nPhone: {phone}\n\n")

        for item, size, qty, price in order_list:
            f.write(f"{item} ({size}) x{qty} = Rs.{qty * price}\n")

        f.write(f"\nTotal: Rs.{final:.2f}\n")

    total_orders += 1
    total_sales += final

    input("\nPress Enter...")


def view_today_orders():
    clear_screen()
    print_header()

    today = datetime.now().strftime("%d-%m-%Y")

    if not os.path.exists("all_orders.txt"):
        print("No orders found")
        input("Press Enter...")
        return

    with open("all_orders.txt", "r") as f:
        content = f.read().split("=" * 40)

        found = False
        for block in content:
            if today in block:
                print(block)
                print("=" * 40)
                found = True

        if not found:
            print("No orders today")

    input("\nPress Enter...")


def show_daily_sales_graph():
    daily_sales = defaultdict(float)

    if not os.path.exists("all_orders.txt"):
        print("No data")
        input("Press Enter...")
        return

    with open("all_orders.txt", "r") as f:
        content = f.read().split("=" * 40)

        for block in content:
            date = None
            total = 0

            for line in block.split("\n"):
                if "Date:" in line:
                    date = line.split("Date:")[1].strip().split(" ")[0]
                if "Total: Rs." in line:
                    total = float(line.split("Rs.")[1])

            if date:
                daily_sales[date] += total

    plt.figure()
    plt.plot(list(daily_sales.keys()), list(daily_sales.values()), marker='o')
    plt.title("Daily Sales Report")
    plt.xlabel("Date")
    plt.ylabel("Sales (Rs.)")
    plt.xticks(rotation=30)
    plt.grid()
    plt.show()


def show_item_pie_chart():
    item_sales = {}

    if not os.path.exists("all_orders.txt"):
        print("No data")
        input("Press Enter...")
        return

    with open("all_orders.txt", "r") as f:
        content = f.read().split("=" * 40)

        for block in content:
            for line in block.split("\n"):
                if "x" in line and "Rs." in line:
                    try:
                        item = line.split("(")[0].strip()
                        amount = float(line.split("Rs.")[1])
                        item_sales[item] = item_sales.get(item, 0) + amount
                    except:
                        pass

    if item_sales:
        plt.figure()
        plt.pie(item_sales.values(), labels=item_sales.keys(), autopct='%1.1f%%')
        plt.title("Sales by Item")
        plt.show()


def show_category_pie_chart():
    category_sales = {}

    if not os.path.exists("all_orders.txt"):
        print("No data")
        input("Press Enter...")
        return

    with open("all_orders.txt", "r") as f:
        content = f.read().split("=" * 40)

        for block in content:
            for line in block.split("\n"):
                if "x" in line and "Rs." in line:
                    try:
                        item = line.split("(")[0].strip()
                        amount = float(line.split("Rs.")[1])

                        for category, items in menu.items():
                            if item in items:
                                category_sales[category] = category_sales.get(category, 0) + amount
                    except:
                        pass

    if category_sales:
        plt.figure()
        plt.pie(category_sales.values(), labels=category_sales.keys(), autopct='%1.1f%%')
        plt.title("Sales by Category")
        plt.show()


# ✅ NEW FUNCTIONS
def add_item():
    category = input("Enter category: ").strip()
    if category not in menu:
        menu[category] = {}

    item = input("Enter item name: ").strip()
    price = float(input("Enter price: "))

    menu[category][item] = price
    print("Item added successfully!")


def delete_item():
    item = input("Enter item name to delete: ").strip()

    for category in menu:
        if item in menu[category]:
            del menu[category][item]
            print("Item deleted successfully!")
            return

    print("Item not found!")


def update_item():
    item = input("Enter item name to update: ").strip()

    for category in menu:
        if item in menu[category]:
            new_price = float(input("Enter new price: "))
            menu[category][item] = new_price
            print("Item updated successfully!")
            return

    print("Item not found!")


def admin_mode():
    if input("Enter Admin Password: ") != ADMIN_PASSWORD:
        print("Wrong password")
        input("Press Enter...")
        return

    while True:
        clear_screen()
        print_header()

        print("\n1. View Stats")
        print("2. Daily Sales Graph")
        print("3. Item Pie Chart")
        print("4. Category Pie Chart")
        print("5. Add Item")
        print("6. Delete Item")
        print("7. Update Item")
        print("8. Exit")

        ch = input("Choice: ")

        if ch == "1":
            print(f"\nToday's Orders: {total_orders}")
            print(f"Today's Sales: Rs.{total_sales:.2f}")
            input("Press Enter...")

        elif ch == "2":
            show_daily_sales_graph()

        elif ch == "3":
            show_item_pie_chart()

        elif ch == "4":
            show_category_pie_chart()

        elif ch == "5":
            add_item()
            input("Press Enter...")

        elif ch == "6":
            delete_item()
            input("Press Enter...")

        elif ch == "7":
            update_item()
            input("Press Enter...")

        elif ch == "8":
            break


def main():
    load_today_orders()

    while True:
        clear_screen()
        print_header()

        print("\n1. View Menu")
        print("2. Place Order")
        print("3. View Today's Orders")
        print("4. Admin Mode")
        print("5. Exit")

        ch = input("Choice: ")

        if ch == "1":
            show_menu()
            input("Press Enter...")

        elif ch == "2":
            place_order()

        elif ch == "3":
            view_today_orders()

        elif ch == "4":
            admin_mode()

        elif ch == "5":
            break


if __name__ == "__main__":
    main()