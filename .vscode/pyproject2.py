import os
from datetime import datetime

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

orders_history = []
total_orders = 0
total_sales = 0


def clear_screen():
    print("\n" * 50)


def print_header():
    print("=" * 50)
    print("        ☕ SUNSHINE CAFE ☕")
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
        while True:
            choices = input("\nEnter item numbers (e.g. 1 3 5): ").split()

            if not choices:
                print("Enter at least one item")
                continue

            invalid = [c for c in choices if c not in item_map]
            if invalid:
                print("Invalid items:", invalid)
                continue

            break

        for choice in choices:
            item, price, category = item_map[choice]

            while True:
                try:
                    qty = int(input(f"Quantity for {item}: "))
                    if qty > 0:
                        break
                    print("Invalid quantity")
                except:
                    print("Enter number only")

            size = "-"
            if category == "Drinks":
                size = input("Size (Small/Medium): ").title()
                if size not in ["Small", "Medium"]:
                    size = "Small"

                if size == "Medium":
                    price += 20

            order_list.append((item, size, qty, price))

        more = input("\nPress Enter to finalize OR type 'y' to add more: ")
        if more.lower() != 'y':
            break

    # BILL
    clear_screen()
    print_header()

    now = datetime.now().strftime("%d-%m-%Y %I:%M %p")

    print(f"\nName: {name}")
    print(f"Phone: {phone}")
    print(f"Date: {now}")

    print("\n" + "-" * 50)
    print(f"{'Item':<15}{'Size':<10}{'Qty':<5}{'Price':<8}{'Total'}")
    print("-" * 50)

    grand_total = 0

    for item, size, qty, price in order_list:
        total = qty * price
        grand_total += total
        print(f"{item:<15}{size:<10}{qty:<5}{price:<8}{total}")

    gst = grand_total * 0.05
    final = grand_total + gst

    print("-" * 50)
    print(f"{'Subtotal':<30}Rs.{grand_total}")
    print(f"{'GST (5%)':<30}Rs.{gst:.2f}")
    print(f"{'Total':<30}Rs.{final:.2f}")

    # SAVE ALL ORDERS IN ONE FILE
    with open("all_orders.txt", "a") as f:
        f.write("\n" + "=" * 40 + "\n")
        f.write("SUNSHINE CAFE BILL\n")
        f.write(f"Name: {name}\nPhone: {phone}\nDate: {now}\n\n")

        for item, size, qty, price in order_list:
            f.write(f"{item} ({size}) x{qty} = Rs.{qty * price}\n")

        f.write(f"\nTotal: Rs.{final:.2f}\n")

    print("\nOrder saved in all_orders.txt")

    total_orders += 1
    total_sales += final

    orders_history.append({
        "name": name,
        "phone": phone,
        "total": final,
        "items": order_list
    })

    input("\nPress Enter...")


def view_orders():
    clear_screen()
    print_header()

    if not orders_history:
        print("\nNo orders yet")
    else:
        for i, order in enumerate(orders_history, 1):
            print(f"\nOrder {i}")
            print(f"Name: {order['name']}")
            print(f"Phone: {order['phone']}")
            print(f"Total: Rs.{order['total']:.2f}")

    input("\nPress Enter...")


def admin_mode():
    clear_screen()
    print_header()

    password = input("Enter Admin Password: ")

    if password != ADMIN_PASSWORD:
        print("Wrong password")
        input("Press Enter...")
        return

    while True:
        clear_screen()
        print_header()

        print("\nADMIN PANEL")
        print("1. View Menu")
        print("2. Add Item")
        print("3. Remove Item")
        print("4. Update Price")
        print("5. View Stats")
        print("6. Exit")

        choice = input("Choice: ")

        if choice == "1":
            show_menu()
            input("Press Enter...")

        elif choice == "2":
            try:
                category = input("Category: ").title()
                item = input("Item: ").title()
                price = int(input("Price: "))
                menu.setdefault(category, {})[item] = price
            except:
                print("Invalid input")

        elif choice == "3":
            category = input("Category: ").title()
            item = input("Item: ").title()
            if category in menu and item in menu[category]:
                del menu[category][item]

        elif choice == "4":
            try:
                category = input("Category: ").title()
                item = input("Item: ").title()
                price = int(input("New Price: "))
                menu[category][item] = price
            except:
                print("Error")

        elif choice == "5":
            print(f"\nTotal Orders: {total_orders}")
            print(f"Total Sales: Rs.{total_sales:.2f}")
            input("Press Enter...")

        elif choice == "6":
            break


def main():
    while True:
        clear_screen()
        print_header()

        print("\n1. View Menu")
        print("2. Place Order")
        print("3. Admin Mode")
        print("4. View Orders")
        print("5. Exit")

        choice = input("Choice: ")

        if choice == "1":
            show_menu()
            input("Press Enter...")

        elif choice == "2":
            place_order()

        elif choice == "3":
            admin_mode()

        elif choice == "4":
            view_orders()

        elif choice == "5":
            break


if __name__ == "__main__":
    main()