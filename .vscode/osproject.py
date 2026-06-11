class Process:
    def __init__(self, pid, at, bt, pr):
        self.pid = pid
        self.at = at
        self.bt = bt
        self.pr = pr
        self.remaining = bt
        self.ct = 0
        self.tat = 0
        self.wt = 0


def reset_processes(processes):
    # Reset values so we can run again
    for p in processes:
        p.remaining = p.bt
        p.ct = 0
        p.tat = 0
        p.wt = 0


def priority_scheduling(processes, preemptive):
    time = 0
    completed = 0
    n = len(processes)
    gantt = []

    while completed < n:
        ready = [p for p in processes if p.at <= time and p.remaining > 0]

        if not ready:
            gantt.append("idle")
            time += 1
            continue

        ready.sort(key=lambda x: (x.pr, x.at))
        current = ready[0]

        if preemptive:
            gantt.append(current.pid)
            current.remaining -= 1
            time += 1

            if current.remaining == 0:
                current.ct = time
                completed += 1
        else:
            gantt.append(current.pid)
            time += current.remaining
            current.remaining = 0
            current.ct = time
            completed += 1

    # Calculate times
    total_wt = 0
    total_tat = 0

    for p in processes:
        p.tat = p.ct - p.at
        p.wt = p.tat - p.bt
        total_wt += p.wt
        total_tat += p.tat

    avg_wt = total_wt / n
    avg_tat = total_tat / n

    return gantt, avg_wt, avg_tat


def print_results(processes, gantt, avg_wt, avg_tat, title):
    print(f"\n===== {title} =====")

    print("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT")
    for p in processes:
        print(f"{p.pid}\t{p.at}\t{p.bt}\t{p.pr}\t{p.ct}\t{p.tat}\t{p.wt}")

    print("\nAverage Waiting Time =", round(avg_wt, 2))
    print("Average Turnaround Time =", round(avg_tat, 2))

    print("\nGantt Chart:")
    print(" | ".join(gantt))


# ===== MAIN =====

n = int(input("Enter number of processes: "))
processes = []

for i in range(n):
    print(f"\nProcess P{i}")
    at = int(input("Enter Arrival Time: "))
    bt = int(input("Enter Burst Time: "))
    pr = int(input("Enter Priority (lower number = higher priority): "))
    
    processes.append(Process(f"P{i}", at, bt, pr))


mode = input("\nEnter type (P = Preemptive / NP = Non-Preemptive): ").strip().upper()

# First run
if mode == "P":
    gantt, avg_wt, avg_tat = priority_scheduling(processes, True)
    print_results(processes, gantt, avg_wt, avg_tat, "Preemptive Priority")

    choice = input("\nDo you also want Non-Preemptive? (Y/N): ").strip().upper()
    
    if choice == "Y":
        reset_processes(processes)
        gantt, avg_wt, avg_tat = priority_scheduling(processes, False)
        print_results(processes, gantt, avg_wt, avg_tat, "Non-Preemptive Priority")

else:
    gantt, avg_wt, avg_tat = priority_scheduling(processes, False)
    print_results(processes, gantt, avg_wt, avg_tat, "Non-Preemptive Priority")

    choice = input("\nDo you also want Preemptive? (Y/N): ").strip().upper()
    
    if choice == "Y":
        reset_processes(processes)
        gantt, avg_wt, avg_tat = priority_scheduling(processes, True)
        print_results(processes, gantt, avg_wt, avg_tat, "Preemptive Priority")