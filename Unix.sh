import os

def shell():
    while True:
        command = input("#cisfun$ ")
        
        if not command:
            continue
        
        try:
            os.execve(command, [command], os.environ)
        except FileNotFoundError:
            print(f"{command}: command not found")
