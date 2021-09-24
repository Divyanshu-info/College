from tabulate import tabulate
Process = [1, 2, 3, 4, 5]
Arrival_Time = [2, 5, 1, 0, 4]
Burst_Time = [6, 3, 8, 3, 4]
for i in range(len(Process)):
    for j in range(len(Process)):
        if Arrival_Time[i] < Arrival_Time[j]:
            Arrival_Time[i], Arrival_Time[j] = Arrival_Time[j], Arrival_Time[i]
            Process[i], Process[j] = Process[j], Process[i]
            Burst_Time[i], Burst_Time[j] = Burst_Time[j], Burst_Time[i]

if Arrival_Time[0] != 0:
    for i in range(1, len(Process)):
        Arrival_Time[i] -= Arrival_Time[0]

Completion_Time = []
TurnAround_Time = []
Waiting_Time = []

for i in range(len(Process)):
    if Arrival_Time[i] == Arrival_Time[i+1]:
        pass
    Completion_Time.append(sum(Completion_Time[i-1:i]) + Burst_Time[i])
    TurnAround_Time.append(Completion_Time[i] - Arrival_Time[i])
    Waiting_Time.append(TurnAround_Time[i] - Burst_Time[i])
    
print(Process)
print(Arrival_Time)
print(Burst_Time)
print(Completion_Time)
print(TurnAround_Time)
print(Waiting_Time)
table = [Process, Arrival_Time, Burst_Time,
         Completion_Time, TurnAround_Time, Waiting_Time]
print(tabulate(table))
