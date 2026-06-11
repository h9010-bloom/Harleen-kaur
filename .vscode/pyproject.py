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
    os.system('cls' if os.name == 'nt' else 'clear')


def print_line():
    print("=" * 50)


def print_header():
    print_line()
    print("        ☕  SUNSHINE CAFE  ☕")
    print("       Your Daily Sip of Happiness")
    print_line()


def show_menu():
    clear_screen()
    print_header()
    print("\nMENU\n")

    item_number = 1
    item_map = {}

    for category, items in menu.items():
        print(f"\n--- {category} ---")
        for item, price in items.items():
            print(f"{item_number}. {item} - Rs.{price}")
            item_map[str(item_number)] = (item, price)
            item_number += 1

    return item_map


def place_order():
    global total_orders, total_sales

    clear_screen()
    print_header()
    print("\nPLACE ORDER\n")

    customer_name = input("Enter name: ").strip()

    while True:
        customer_phone = input("Enter phone: ")
        if customer_phone.isdigit() and len(customer_phone) == 10:
            break
        else:
            print("Invalid phone number")

    item_map = show_menu()
    order_list = []

    while True:
        choice = input("Enter item number (0 to finish): ")

        if choice == "0":
            if not order_list:
                print("No items selected")
                continue
            break

        if choice not in item_map:
            print("Invalid choice")
            continue

        item_name, price = item_map[choice]

        try:
            qty = int(input(f"Quantity for {item_name}: "))
            if qty <= 0:
                continue
        except:
            continue

        order_list.append((item_name, qty, price))

    clear_screen()
    print_header()
    print("\nBILL\n")

    now = datetime.now().strftime("%d %B %Y %I:%M %p")

    print(f"Name: {customer_name}")
    print(f"Phone: {customer_phone}")
    print(f"Date: {now}\n")

    grand_total = 0

    for item, qty, price in order_list:
        total = qty * price
        grand_total += total
        print(f"{item} x{qty} = Rs.{total}")

    gst = grand_total * 0.05
    final_amount = grand_total + gst

    print(f"\nSubtotal: Rs.{grand_total}")
    print(f"GST: Rs.{gst:.2f}")
    print(f"Total: Rs.{final_amount:.2f}")

    filename = f"bill_{customer_name}.txt"

    with open(filename, "w") as f:
        f.write("SUNSHINE CAFE BILL\n")
        f.write(f"Name: {customer_name}\n")
        f.write(f"Phone: {customer_phone}\n")
        f.write(f"Date: {now}\n\n")

        for item, qty, price in order_list:
            f.write(f"{item} x{qty} = Rs.{qty * price}\n")

        f.write(f"\nTotal: Rs.{final_amount:.2f}")

    print(f"\nBill saved as {filename}")

    total_orders += 1
    total_sales += final_amount

    orders_history.append({
        "name": customer_name,
        "phone": customer_phone,
        "total": final_amount,
        "items": order_list
    })

    input("\nPress Enter...")


def view_orders():
    clear_screen()
    print_header()
    print("\nPREVIOUS ORDERS\n")

    if not orders_history:
        print("No orders yet")
    else:
        for i, order in enumerate(orders_history, 1):
            print(f"\nOrder {i}")
            print(f"Name: {order['name']}")
            print(f"Phone: {order['phone']}")
            print(f"Total: Rs.{order['total']}")
            for item, qty, price in order["items"]:
                print(f"{item} x{qty}")

    input("\nPress Enter...")


def admin_mode():
    clear_screen()
    print_header()

    password = input("Enter password: ")

    if password != ADMIN_PASSWORD:
        print("Wrong password")
        input("Press Enter...")
        return

    while True:
        clear_screen()
        print_header()
        print("\nADMIN PANEL\n")
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
            category = input("Category (Drinks/Food/Desserts): ").title()
            if category not in menu:
                print("Invalid category")
                input("Press Enter...")
                continue

            item = input("Item name: ").title()
            try:
                price = int(input("Price: "))
                menu[category][item] = price
            except:
                continue

        elif choice == "3":
            category = input("Category: ").title()
            item = input("Item: ").title()

            if category in menu and item in menu[category]:
                del menu[category][item]

        elif choice == "4":
            category = input("Category: ").title()
            item = input("Item: ").title()

            if category in menu and item in menu[category]:
                try:
                    price = int(input("New price: "))
                    menu[category][item] = price
                except:
                    continue

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

        choice = input("Enter choice: ")

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