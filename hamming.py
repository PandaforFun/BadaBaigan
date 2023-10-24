def calculate_hamming_code(data):
    hamming_code = [0] * 7

    hamming_code[0] = (int(data[0]) ^ int(data[1]) ^ int(data[3]))
    hamming_code[1] = (int(data[0]) ^ int(data[2]) ^ int(data[3]))
    hamming_code[2] = (int(data[1]) ^ int(data[2]) ^ int(data[3]))

    hamming_code[3] = int(data[0])
    hamming_code[4] = int(data[1])
    hamming_code[5] = int(data[2])
    hamming_code[6] = int(data[3])

    return hamming_code

def check_from_user(user, coded):
    return user == coded

data = input("Enter 4-bit data to encode in Hamming code: ")
if len(data) != 4:
    print("Invalid input! Please enter a 4-bit data.")
else:
    hamming_code = calculate_hamming_code(data)
    user_hamming = list(map(int, input("Enter the 7-digit Hamming code for comparison: ").split()))

    if check_from_user(user_hamming, hamming_code):
        print("No errors detected!")
    else:
        print("Error Detected!")

#Output:
# 1. Enter 4-bit data to encode in Hamming code: 1011
# Enter the 7-digit Hamming code for comparison: 1 1 1 1 1 1 1
# Error Detected!

# 2. Enter 4-bit data to encode in Hamming code: 1111
# Enter the 7-digit Hamming code for comparison: 1 1 1 1 1 1 1
# No errors detected!
