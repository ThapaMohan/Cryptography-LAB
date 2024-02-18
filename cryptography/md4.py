import hashlib

def md4_example(data):
    md4_hash = hashlib.new('md4', data.encode()).hexdigest()
    print(f"MD4 hash of '{data}':\n{md4_hash}\n")

def md5_example(data):
    md5_hash = hashlib.md5(data.encode()).hexdigest()
    print(f"MD5 hash of '{data}':\n{md5_hash}\n")

if __name__ == "__main__":
    data = "cryptography"

    md4_example(data)
    md5_example(data)
