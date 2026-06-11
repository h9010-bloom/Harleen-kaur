import random
import json
import os

class IndianFlightSystem:
    def __init__(self):
        self.flights_file = "flights_db.json"
        self.bookings_file = "bookings_db.json"
        
        # Default data if files don't exist
        self.default_flights = {
            "IND-ASR": {
                "from": "Amritsar", "to": "Delhi", "price": 3200, "seats": 20,
                "dep": "2026-06-15 06:00 AM", "arr": "2026-06-15 07:15 AM"
            },
            "IND-DEL": {
                "from": "Delhi", "to": "Mumbai", "price": 4800, "seats": 15,
                "dep": "2026-06-15 10:30 AM", "arr": "2026-06-15 12:45 PM"
            },
            "IND-BOM": {
                "from": "Mumbai", "to": "Bangalore", "price": 5200, "seats": 10,
                "dep": "2026-06-16 02:00 PM", "arr": "2026-06-16 03:45 PM"
            },
            "IND-CCU": {
                "from": "Kolkata", "to": "Delhi", "price": 6100, "seats": 8,
                "dep": "2026-06-16 08:00 PM", "arr": "2026-06-16 10:30 PM"
            }
        }
        
        # Load existing data or initialize with defaults
        self.load_data()

    def load_data(self):
        """Basic File Handling: Reading data from JSON files"""
        if os.path.exists(self.flights_file):
            with open(self.flights_file, "r") as f:
                self.flights = json.load(f)
        else:
            self.flights = self.default_flights

        if os.path.exists(self.bookings_file):
            with open(self.bookings_file, "r") as f:
                self.booked_tickets = json.load(f)
        else:
            self.booked_tickets = {}

    def save_data(self):
        """Basic File Handling: Writing data to JSON files"""
        with open(self.flights_file, "w") as f:
            json.dump(self.flights, f, indent=4)
        with open(self.bookings_file, "w") as f:
            json.dump(self.booked_tickets, f, indent=4)

    def display_schedule(self):
        print("\n" + "="*115)
        print(f"{'FLIGHT ID':<12} {'FROM':<15} {'TO':<15} {'PRICE':<10} {'DEPARTURE':<22} {'ARRIVAL':<22} {'SEATS'}")
        print("-" * 115)
        for fid, info in self.flights.items():
            print(f"{fid:<12} {info['from']:<15} {info['to']:<15} ₹{info['price']:<9} {info['dep']:<22} {info['arr']:<22} {info['seats']}")
        print("="*115)

    def book_ticket(self):
        self.display_schedule()
        fid = input("\nEnter Flight ID: ").upper()

        if fid in self.flights:
            try:
                num_seats = int(input(f"How many seats do you want to book? (Available: {self.flights[fid]['seats']}): "))
            except ValueError:
                print(" Invalid input. Please enter a number.")
                return

            if num_seats <= 0:
                print(" You must book at least 1 seat.")
                return
            
            if num_seats > self.flights[fid]['seats']:
                print(f" Sorry, only {self.flights[fid]['seats']} seats are available.")
                return

            print("\n--- CHOOSE CLASS ---")
            print("1. Economy Class (Base Price)")
            print("2. Business Class (+₹3,500 per seat)")
            cls_choice = input("Select (1/2): ")
            
            f_class = "Business" if cls_choice == "2" else "Economy"
            price_per_seat = self.flights[fid]['price'] + (3500 if f_class == "Business" else 0)
            total_price = price_per_seat * num_seats

            passengers = []
            for i in range(num_seats):
                name = input(f"Enter Name for Passenger {i+1}: ")
                passengers.append(name)

            print(f"\n--- PAYMENT SUMMARY ---")
            print(f"Seats: {num_seats} | Class: {f_class}")
            print(f"Total Fare: ₹{total_price}")
            print("\nSelect Payment Mode: 1. UPI (GPay/Paytm)  2. Card  3. Net Banking")
            
            pay_mode = input("Choice: ")
            modes = {"1": "UPI", "2": "Card", "3": "Net Banking"}
            final_pay_mode = modes.get(pay_mode, "UPI")

            print(f"\nProcessing ₹{total_price} via {final_pay_mode}...")
            print("Transaction Successful! ")

            pnr = f"PNR{random.randint(10000, 99999)}"
            
            self.booked_tickets[pnr] = {
                "names": passengers, 
                "flight": fid, 
                "class": f_class, 
                "paid": total_price,
                "count": num_seats,
                "from": self.flights[fid]['from'], 
                "to": self.flights[fid]['to'],
                "dep": self.flights[fid]['dep'], 
                "arr": self.flights[fid]['arr']
            }
            
            self.flights[fid]['seats'] -= num_seats
            
            # Save data after every booking
            self.save_data()

            print("\n" + "*"*50)
            print("          INDIAN AIRLINES E-TICKET          ")
            print("*"*50)
            print(f"PNR NUMBER  : {pnr}")
            print(f"PASSENGERS  : {', '.join(passengers)}")
            print(f"TOTAL SEATS : {num_seats}")
            print(f"ROUTE       : {self.flights[fid]['from']} to {self.flights[fid]['to']}")
            print(f"CLASS       : {f_class}")
            print(f"DEPARTURE   : {self.flights[fid]['dep']}")
            print(f"TOTAL PAID  : ₹{total_price}")
            print("*"*50)
        else:
            print("\n Error: Invalid Flight ID.")

    def cancel_ticket(self):
        pnr = input("\nEnter PNR to cancel: ").upper()
        if pnr in self.booked_tickets:
            ticket = self.booked_tickets[pnr]
            fid = ticket['flight']
            
            self.flights[fid]['seats'] += ticket['count']
            del self.booked_tickets[pnr]
            
            # Save data after every cancellation
            self.save_data()
            print(f"Cancellation Successful. {ticket['count']} seats released for PNR {pnr}.")
        else:
            print(" Invalid PNR.")

# --- Program Interface ---
airways = IndianFlightSystem()

while True:
    print("\n--- MAIN MENU ---")
    print("1. Check Flights\n2. Book Ticket\n3. Cancel Ticket\n4. Exit")
    choice = input("Select (1-4): ")
    
    if choice == '1': airways.display_schedule()
    elif choice == '2': airways.book_ticket()
    elif choice == '3': airways.cancel_ticket()
    elif choice == '4': 
        airways.save_data() # Final save before exit
        break
    else: print("Invalid Choice!")