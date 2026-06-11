import sqlite3

# Connect to SQLite DB
conn = sqlite3.connect("hospital.db")
cur = conn.cursor()


def newPatient():
    print("Add New Patient")
    pid = input("Enter Patient ID: ")
    name = input("Enter Name: ")
    disease = input("Enter Disease: ")
    fee = float(input("Enter Fee: "))
    doctor = input("Enter Doctor Name: ")

    cur.execute("INSERT INTO patient VALUES (:1, :2, :3, :4, :5)",
                (pid, name, disease, fee, doctor))
    conn.commit()
    print("Record Inserted")


def editPatient():
    pid = input("Enter Patient ID to modify: ")

    cur.execute("SELECT * FROM patient WHERE patientid=:1", (pid,))
    rec = cur.fetchone()

    if rec:
        print("Old Record:", rec)

        name = input("Enter New Name: ")
        disease = input("Enter Disease: ")
        fee = float(input("Enter Fee: "))
        doctor = input("Enter Doctor: ")

        cur.execute("""
            UPDATE patient
            SET patientname=:1, disease=:2, fee=:3, doctorname=:4
            WHERE patientid=:5
        """, (name, disease, fee, doctor, pid))

        conn.commit()
        print("Record Updated")
    else:
        print("Record Not Found")


def delPatient():
    pid = input("Enter Patient ID to delete: ")

    cur.execute("SELECT * FROM patient WHERE patientid=:1", (pid,))
    rec = cur.fetchone()

    if rec:
        print(rec)
        choice = input("Delete? (y/n): ")
        if choice.lower() == 'y':
            cur.execute("DELETE FROM patient WHERE patientid=:1", (pid,))
            conn.commit()
            print("Record Deleted")
    else:
        print("Record Not Found")


def searchPatient():
    pid = input("Enter Patient ID to search: ")

    cur.execute("SELECT * FROM patient WHERE patientid=:1", (pid,))
    rec = cur.fetchone()

    if rec:
        print("Record Found:", rec)
    else:
        print("Record Not Found")


def listPatients():
    print("All Patients:")
    cur.execute("SELECT * FROM patient")

    for rec in cur:
        print(rec)


def menu():
    while True:
        print("\n--- Hospital Management System ---")
        print("1. Add Patient")
        print("2. Modify Patient")
        print("3. Delete Patient")
        print("4. Search Patient")
        print("5. List Patients")
        print("6. Exit")

        choice = int(input("Enter choice: "))

        if choice == 1:
            newPatient()
        elif choice == 2:
            editPatient()
        elif choice == 3:
            delPatient()
        elif choice == 4:
            searchPatient()
        elif choice == 5:
            listPatients()
        elif choice == 6:
            break
        else:
            print("Invalid choice")


menu()

cur.close()
conn.close()