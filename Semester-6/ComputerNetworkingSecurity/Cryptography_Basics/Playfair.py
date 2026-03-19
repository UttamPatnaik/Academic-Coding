def prepare_key_matrix(keyword):
    
    clean_key = []
    seen = set()
    keyword = keyword.upper()
    
    for char in keyword:
        if char.isalpha():
            if char == 'J':
                char = 'I'
            if char not in seen:
                clean_key.append(char)
                seen.add(char)
    
   
    for c in range(ord('A'), ord('Z') + 1):
        char = chr(c)
        if char == 'J':
            continue
        if char not in seen:
            clean_key.append(char)
            seen.add(char)
    
    
    matrix = []
    for i in range(0, 25, 5):
        matrix.append(clean_key[i:i+5])
    
    return matrix


def find_position(matrix, ch):
    if ch == 'J':
        ch = 'I'
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == ch:
                return i, j
    return -1, -1  


def prepare_plaintext(plaintext):
    cleaned = []
    plaintext = plaintext.upper()
    
    for char in plaintext:
        if char.isalpha():
            if char == 'J':
                char = 'I'
            cleaned.append(char)
    
    prepared = []
    i = 0
    while i < len(cleaned):
        first = cleaned[i]
        prepared.append(first)
        
        if i + 1 >= len(cleaned):
            prepared.append('X')
            break
        
        second = cleaned[i + 1]
        if first == second:
            prepared.append('X')
            i += 1  
        else:
            prepared.append(second)
            i += 2
    
    return ''.join(prepared)


def encrypt_pair(matrix, a, b):
    r1, c1 = find_position(matrix, a)
    r2, c2 = find_position(matrix, b)
    
    if r1 == r2:          
        return matrix[r1][(c1 + 1) % 5] + matrix[r2][(c2 + 1) % 5]
    elif c1 == c2:         
        return matrix[(r1 + 1) % 5][c1] + matrix[(r2 + 1) % 5][c2]
    else:                 
        return matrix[r1][c2] + matrix[r2][c1]


def decrypt_pair(matrix, a, b):
    r1, c1 = find_position(matrix, a)
    r2, c2 = find_position(matrix, b)
    
    if r1 == r2:           
        return matrix[r1][(c1 - 1 + 5) % 5] + matrix[r2][(c2 - 1 + 5) % 5]
    elif c1 == c2:        
        return matrix[(r1 - 1 + 5) % 5][c1] + matrix[(r2 - 1 + 5) % 5][c2]
    else:                
        return matrix[r1][c2] + matrix[r2][c1]


def playfair_encrypt(plaintext, keyword):
    matrix = prepare_key_matrix(keyword)
    prepared = prepare_plaintext(plaintext)
    ciphertext = []
    
    for i in range(0, len(prepared), 2):
        a = prepared[i]
        b = prepared[i + 1]
        ciphertext.append(encrypt_pair(matrix, a, b))
    
    return ''.join(ciphertext)


def playfair_decrypt(ciphertext, keyword):
    matrix = prepare_key_matrix(keyword)
    ciphertext = ''.join(c for c in ciphertext.upper() if c.isalpha())
    plaintext = []
    
    for i in range(0, len(ciphertext), 2):
        a = ciphertext[i]
        b = ciphertext[i + 1]
        plaintext.append(decrypt_pair(matrix, a, b))
    
    result = ''.join(plaintext)
    if result.endswith('X'):
        result = result[:-1]
    
    return result


def main():
    keyword = input("Enter keyword: ").strip()
    plaintext = input("Enter plaintext: ").strip()
    
    ciphertext = playfair_encrypt(plaintext, keyword)
    print("\nCiphertext :", ciphertext)
    
    decrypted = playfair_decrypt(ciphertext, keyword)
    print("Decrypted  :", decrypted)


if __name__ == "__main__":
    main()
