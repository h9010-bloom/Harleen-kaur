import tkinter as tk
from tkinter import messagebox, simpledialog
from datetime import datetime

# ---------------- MENU ----------------
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

# ---------------- MAIN WINDOW ----------------
root = tk.Tk()
root.title("☕ Sunshine Cafe")
root.geometry("700x600")
root.minsize(600, 500)
root.maxsize(900, 700)

# ---------------- MENU WINDOW ----------------
def show_menu():
    win = tk.Toplevel(root)
    win.title("Menu")
    win.geometry("400x500")
    win.resizable(False, False)

    row = 0
    for category, items in menu.items():
        tk.Label(win, text=f"-- {category} --", font=("Arial", 12, "bold")).grid(row=row, column=0, sticky="w")
        row += 1
        for item, price in items.items():
            tk.Label(win, text=f"{item} - Rs.{price}").grid(row=row, column=0, sticky="w")
            row += 1

    tk.Button(win, text="Next → Place Order", command=place_order).grid(row=row+1, column=0, pady=20)

# ---------------- ORDER WINDOW ----------------
def place_order():
    order_win = tk.Toplevel(root)
    order_win.title("Place Order")
    order_win.geometry("500x600")

    tk.Label(order_win, text="Name").grid(row=0, column=0)
    name_entry = tk.Entry(order_win)
    name_entry.grid(row=0, column=1)

    tk.Label(order_win, text="Phone").grid(row=1, column=0)
    phone_entry = tk.Entry(order_win)
    phone_entry.grid(row=1, column=1)

    items_vars = []
    row = 2

    # LIVE PRICE UPDATE
    def update_price(label, base_price, size_var, category):
        price = base_price
        if category == "Drinks" and size_var.get() == "Medium":
            price += 20
        label.config(text=f"Rs.{price}")

    for category, items in menu.items():
        tk.Label(order_win, text=f"-- {category} --").grid(row=row, column=0)
        row += 1

        for item, price in items.items():
            var = tk.IntVar()

            tk.Checkbutton(order_win, text=item, variable=var).grid(row=row, column=0, sticky="w")

            qty = tk.Entry(order_win, width=5)
            qty.grid(row=row, column=1)

            price_label = tk.Label(order_win, text=f"Rs.{price}")
            price_label.grid(row=row, column=2)

            size = tk.StringVar(value="Small")

            if category == "Drinks":
                tk.OptionMenu(
                    order_win, size, "Small", "Medium",
                    command=lambda x, l=price_label, p=price, s=size, c=category:
                    update_price(l, p, s, c)
                ).grid(row=row, column=3)
            else:
                size.set("-")

            items_vars.append((item, price, var, qty, size, category))
            row += 1

    # ---------------- BILL ----------------
    def generate_bill():
        global total_orders, total_sales

        name = name_entry.get()
        phone = phone_entry.get()

        # PHONE VALIDATION
        if not phone.isdigit() or len(phone) != 10:
            messagebox.showerror("Error", "Invalid phone number")
            return

        order_list = []
        grand_total = 0

        for item, price, var, qty_entry, size_var, category in items_vars:
            if var.get() == 1:
                try:
                    qty = int(qty_entry.get())
                except:
                    messagebox.showerror("Error", f"Invalid quantity for {item}")
                    return

                size = size_var.get()
                final_price = price

                if category == "Drinks" and size == "Medium":
                    final_price += 20

                total = qty * final_price
                grand_total += total

                order_list.append((item, size, qty, final_price))

        gst = grand_total * 0.05
        final = grand_total + gst

        # BILL WINDOW
        bill_win = tk.Toplevel(order_win)
        bill_win.title("Bill")
        bill_win.geometry("400x500")

        text = tk.Text(bill_win, font=("Arial", 10))
        text.pack()

        now = datetime.now().strftime("%d-%m-%Y %I:%M %p")

        text.insert(tk.END, f"Name: {name}\nPhone: {phone}\nDate: {now}\n\n")

        for item, size, qty, price in order_list:
            text.insert(tk.END, f"{item} ({size}) x{qty} = Rs.{qty*price}\n")

        text.insert(tk.END, f"\nSubtotal: Rs.{grand_total}")
        text.insert(tk.END, f"\nGST: Rs.{gst:.2f}")
        text.insert(tk.END, f"\nTotal: Rs.{final:.2f}")

        # THANK YOU MESSAGE
        tk.Label(
            bill_win,
            text="🙏 Thank You for Ordering! ☕",
            font=("Arial", 14, "bold"),
            fg="green"
        ).pack(pady=10)

        # GO BACK BUTTON
        def go_back():
            bill_win.destroy()
            order_win.destroy()

        tk.Button(
            bill_win,
            text="⬅ Go Back to Menu",
            font=("Arial", 11, "bold"),
            bg="lightblue",
            command=go_back
        ).pack(pady=15)

        # FILE SAVE
        try:
            with open("all_orders.txt", "a") as f:
                f.write("\n" + "="*40 + "\n")
                f.write(f"Name: {name}\nPhone: {phone}\nDate: {now}\n")
                for item, size, qty, price in order_list:
                    f.write(f"{item} ({size}) x{qty} = Rs.{qty*price}\n")
                f.write(f"\nTotal: Rs.{final:.2f}\n")
        except:
            messagebox.showerror("Error", "File saving failed")

        total_orders += 1
        total_sales += final

        orders_history.append({
            "name": name,
            "phone": phone,
            "total": final
        })

    tk.Button(order_win, text="Generate Bill", command=generate_bill).grid(row=row+1, column=0)

# ---------------- ADMIN PANEL ----------------
def admin_panel():
    password = simpledialog.askstring("Admin", "Enter Password", show="*")

    if password != ADMIN_PASSWORD:
        messagebox.showerror("Error", "Wrong Password")
        return

    admin_win = tk.Toplevel(root)
    admin_win.title("Admin Panel")
    admin_win.geometry("250x250")
    admin_win.resizable(False, False)

    def add_item():
        category = simpledialog.askstring("Add", "Category:")
        item = simpledialog.askstring("Add", "Item Name:")
        price = simpledialog.askinteger("Add", "Price:")

        if category and item and price:
            menu.setdefault(category, {})[item] = price
            messagebox.showinfo("Success", f"{item} added!")

    def remove_item():
        category = simpledialog.askstring("Remove", "Category:")
        item = simpledialog.askstring("Remove", "Item Name:")

        if category in menu and item in menu[category]:
            del menu[category][item]
            messagebox.showinfo("Success", f"{item} removed!")
        else:
            messagebox.showerror("Error", "Item not found!")

    def show_stats():
        messagebox.showinfo("Stats", f"Orders: {total_orders}\nSales: Rs.{total_sales:.2f}")

    tk.Button(admin_win, text="Add Item", command=add_item).pack(pady=5)
    tk.Button(admin_win, text="Remove Item", command=remove_item).pack(pady=5)
    tk.Button(admin_win, text="View Stats", command=show_stats).pack(pady=5)

# ---------------- VIEW ORDERS ----------------
def view_orders():
    win = tk.Toplevel(root)
    win.title("Orders")

    text = tk.Text(win)
    text.pack()

    for i, order in enumerate(orders_history, 1):
        text.insert(tk.END, f"\nOrder {i}\n")
        text.insert(tk.END, f"Name: {order['name']}\n")
        text.insert(tk.END, f"Phone: {order['phone']}\n")
        text.insert(tk.END, f"Total: Rs.{order['total']:.2f}\n")

# ---------------- MAIN ----------------
tk.Label(root, text="☕ SUNSHINE CAFE ☕", font=("Arial", 18, "bold")).pack(pady=20)

tk.Button(root, text="View Menu", width=20, command=show_menu).pack(pady=10)
tk.Button(root, text="Place Order", width=20, command=place_order).pack(pady=10)
tk.Button(root, text="Admin Panel", width=20, command=admin_panel).pack(pady=10)
tk.Button(root, text="View Orders", width=20, command=view_orders).pack(pady=10)
tk.Button(root, text="Exit", width=20, command=root.quit).pack(pady=10)

root.mainloop()