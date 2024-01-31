import os
import subprocess

os.makedirs("output", exist_ok=True)

processes = []

for i in range(1, 11):
    command = ["./hello_world", str(i)]
    output_file = f"output/output_{i}.txt"
    with open(output_file, "w") as file:
        process = subprocess.Popen(command, stdout=file)
        processes.append(process)

for process in processes:
    process.wait()

print("All jobs completed.")
