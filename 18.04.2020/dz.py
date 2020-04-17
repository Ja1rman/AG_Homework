def text_to_bits(text, encoding='utf-8', errors='surrogatepass'):
    bits = bin(int.from_bytes(text.encode(encoding, errors), 'big'))[2:]
    return bits.zfill(8 * ((len(bits) + 7) // 8))
    
def text_from_bits(bits, encoding='utf-8', errors='surrogatepass'):
    n = int(bits, 2)
    return n.to_bytes((n.bit_length() + 7) // 8, 'big').decode(encoding, errors) or '\0'

print ('Введите данные')
a = input()

l = list(a) 
code = []

for i in range (0, 12):
    code.append('')

for i in l:
    temp = text_to_bits(i)
    bit1 = int(temp[0]) + int(temp[1]) + int(temp[3]) + int(temp[4]) + int(temp[6])
    if bit1 % 2 == 1:
        bit1 = 1
    else:
        bit1 = 0
        
    bit2 = int(temp[0]) + int(temp[2]) + int(temp[3]) + int(temp[5]) + int(temp[6])
    if bit2 % 2 == 1:
        bit2 = 1
    else:
        bit2 = 0

    bit3 = int(temp[1]) + int(temp[2]) + int(temp[3]) + int(temp[7])
    if bit3 % 2 == 1:
        bit3 = 1
    else:
        bit3 = 0

    bit4 = int(temp[4]) + int(temp[5]) + int(temp[6]) + int(temp[7])
    if bit4 % 2 == 1:
        bit4 = 1
    else:
        bit4 = 0

    for j in range (0, 8):
        code[j] += temp[j]
    
    code[8] += str(bit1)
    code[9] += str(bit2)
    code[10] += str(bit3)
    code[11] += str(bit4)

print ('Выберите буфер удаления данных(0 - 11)')
b = input()

if '0' <= str(b) <= '7':
    code.pop(int(b))
    k = ''
    for i in range (0, len(code[0])):
        k += '0'
    code.insert(int(b), k)
    for i in range (0, len(code[0])):
        bit1 = int(code[0][i]) + int(code[1][i]) + int(code[3][i]) + int(code[4][i]) + int(code[6][i])
        if bit1 % 2 == 1:
            bit1 = 1
        else:
            bit1 = 0
            
        bit2 = int(code[0][i]) + int(code[2][i]) + int(code[3][i]) + int(code[5][i]) + int(code[6][i])
        if bit2 % 2 == 1:
            bit2 = 1
        else:
            bit2 = 0

        bit3 = int(code[1][i]) + int(code[2][i]) + int(code[3][i]) + int(code[7][i])
        if bit3 % 2 == 1:
            bit3 = 1
        else:
            bit3 = 0

        bit4 = int(code[4][i]) + int(code[5][i]) + int(code[6][i]) + int(code[7][i])
        if bit4 % 2 == 1:
            bit4 = 1
        else:
            bit4 = 0

        sum = 0
        
        if str(bit1) != str(code[8][i]):
            sum += 1
        
        if str(bit2) != str(code[9][i]):
            sum += 2
        
        if str(bit3) != str(code[10][i]):
            sum += 4

        if str(bit4) != str(code[11][i]):
            sum += 8

        if sum != 0:
            if sum == 3:
                p = ''
                if code[0][i] == '1':
                    p = '0'
                else:
                    p = '1'
                temp = list(code.pop(0))
                temp.pop(i)
                temp.insert(i, p)
                myString = ''.join(temp)
                code.insert(0, myString)
            elif sum == 5:
                p = ''
                if code[1][i] == '1':
                    p = '0'
                else:
                    p = '1'
                temp = list(code.pop(1))
                temp.pop(i)
                temp.insert(i, p)
                myString = ''.join(temp)
                code.insert(1, myString)
            elif sum == 6:
                p = ''
                if code[2][i] == '1':
                    p = '0'
                else:
                    p = '1'    
                temp = list(code.pop(2))
                temp.pop(i)
                temp.insert(i, p)
                myString = ''.join(temp)
                code.insert(2, myString)
            elif sum == 7:
                p = ''
                if code[3][i] == '1':
                    p = '0'
                else:
                    p = '1'    
                temp = list(code.pop(3))
                temp.pop(i)
                temp.insert(i, p)
                myString = ''.join(temp)
                code.insert(3, myString)
            else:
                p = ''
                if code[sum - 5][i] == '1':
                    p = '0'
                else:
                    p = '1'
                temp = list(code.pop(sum - 5))
                temp.pop(i)  
                temp.insert(i, p)  
                myString = ''.join(temp)
                code.insert(sum - 5, myString)
else:
    if str(b) > '11' or str(b) < '0':
        print('Error')

string = ''
for i in range (0, len(code[0])):
    temp = ''
    for j in range (0, 8):
        temp += code[j][i]
    string += text_from_bits(temp)

print ('Было до удаления:' + a)
print ('Стало после удаления:' + string)
