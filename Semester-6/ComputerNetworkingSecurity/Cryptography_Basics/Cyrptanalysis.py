def caesar_decrypt(ciphertext, shift):
    result = []
    for char in ciphertext:
        if char.isalpha():
            # Determine base ('A' or 'a')
            base = ord('A') if char.isupper() else ord('a')
            # Decrypt: (char - base - shift) mod 26 + base
            decrypted = chr((ord(char) - base - shift + 26) % 26 + base)
            result.append(decrypted)
        else:
            # Keep spaces, numbers, punctuation unchanged
            result.append(char)
    return ''.join(result)


def main():
    print("=== Caesar Cipher Brute Force Cryptanalysis ===")
    ciphertext = input("\nEnter the ciphertext: ").upper()
    
    print("\nTrying all 26 possible shifts...\n")
    
    for shift in range(26):
        plaintext = caesar_decrypt(ciphertext, shift)
        print(f"Shift {shift:2d}  →  {plaintext}")
    
    print("\n=== END OF BRUTE FORCE ===")
    print("Look for the line that makes readable English.")
    print("That shift value is the key that breaks the cipher.")


if __name__ == "__main__":
    main()
