# Definición de la hash table (diccionario)
diccionario = {}

# Función para imprimir todos los elementos de la hash table
def printElements():
    print("Elementos en la Hash Table:")
    for key, value in diccionario.items():
        print(f"Clave: {key}, Valor: {value}")

# Función para insertar un elemento en la hash table
def insert(key, value):
    diccionario[key] = value
    print("Elemento insertado")

# Función para buscar un elemento en la hash table
def search(key):
    if key in diccionario:
        return diccionario[key]
    else:
        return None

# Función para actualizar el valor de un elemento en la hash table
def update(key, newValue):
    if key in diccionario:
        diccionario[key] = newValue
        print("Elemento actualizado")
    else:
        print("Elemento no encontrado")

# Función para eliminar un elemento de la hash table
def removeElement(key):
    if key in diccionario:
        del diccionario[key]
        print("Elemento eliminado")
    else:
        print("Elemento no encontrado")

# Bucle principal
while True:
    print("\n---- Hash Table ----")
    print("1. Insertar elemento")
    print("2. Buscar elemento")
    print("3. Actualizar elemento")
    print("4. Eliminar elemento")
    print("5. Ver todos los elementos")
    print("6. Salir")
    opcion = int(input("Seleccione una opción: "))

    if opcion == 1:
        key = input("Ingrese la clave: ")
        value = input("Ingrese el valor: ")
        insert(key, value)
    elif opcion == 2:
        key = input("Ingrese la clave: ")
        value = search(key)
        if value is not None:
            print(f"Valor encontrado: {value}")
        else:
            print("Elemento no encontrado")
    elif opcion == 3:
        key = input("Ingrese la clave: ")
        newValue = input("Ingrese el nuevo valor: ")
        update(key, newValue)
    elif opcion == 4:
        key = input("Ingrese la clave: ")
        removeElement(key)
    elif opcion == 5:
        printElements()
    elif opcion == 6:
        print("Saliendo...")
        break
    else:
        print("Opción inválida")
