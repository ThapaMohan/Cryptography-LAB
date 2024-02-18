import hashlib

def sha1_example(data):
    sha1_hash = hashlib.sha1(data.encode()).hexdigest()
    print(f"SHA-1 hash of '{data}':\n{sha1_hash}\n")3

def sha2_example(data, algorithm='sha256'):
    sha2_hash = hashlib.new(algorithm, data.encode()).hexdigest()
    print(f"{algorithm.upper()} hash of '{data}':\n{sha2_hash}\n")

if __name__ == "__main__":
    data = "cryptography"

    sha1_example(data)
    sha2_example(data, algorithm='sha224')
    sha2_example(data, algorithm='sha256')
    sha2_example(data, algorithm='sha384')
    sha2_example(data, algorithm='sha512')