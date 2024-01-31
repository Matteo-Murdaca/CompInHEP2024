import re

#2:
with open("brilcalc.log", "r") as f:
    isheader = False  
    index = None  
    
    for line in f:
        if not isheader and "totrecorded(/pb)" in line:
            isheader = True
            headers = [header.strip() for header in line.split('|')]
            index = headers.index("totrecorded(/pb)")
            
        elif isheader and "|" in line:
            columns = [column.strip() for column in line.split('|')]
            
            if index is not None and len(columns) > index:
                value = columns[index]
                finalvalue = 1 / (float(value) * 1000)
                print('totrecorded = ', finalvalue, 'fb^-1')
                break  

#3:

values = {}

with open("brilcalc.log", "r") as f:
    isheader = False
    index = None

    for line in f:
        if not isheader and "recorded(/pb)" in line:
            isheader = True
            headers = [header.strip() for header in line.split('|')]
            index = headers.index("recorded(/pb)")

        elif isheader and "|" in line:
            columns = [column.strip() for column in line.split('|')]

            if index is not None and len(columns) > index:
                value = columns[index]

                if value.replace(".", "", 1).isdigit():
                    value = float(value)
                    run_fill = (columns[0], columns[1])  

                    values[run_fill] = values.get(run_fill, 0) + value

for run_fill, accumulated_value in values.items():
    accumulated_value_fb = 1 / (accumulated_value * 1000)

print('accumulated_value = ', accumulated_value_fb, 'fb^-1')
if accumulated_value_fb == finalvalue:
    print("Sum matches the given summary value.")
else:
    print("Sum does not match the given summary value.")



        



