from cryptography.fernet import Fernet
key = Fernet.generate_key()
f = Fernet(key)
message = "123"
token = f.encrypt(bytes(message, 'utf-8'))

print(token)
print(str(f.decrypt(token)).__len__())

