# Crear un diccionario vacío
diccionario = {}

# Insertar elementos en el diccionario
diccionario['clave1'] = 'valor1'
diccionario['clave2'] = 'valor2'

# Acceder a elementos en el diccionario
print(diccionario['clave1'])  # Imprime 'valor1'

# Verificar si una clave está en el diccionario
if 'clave2' in diccionario:
    print('La clave2 está en el diccionario')

# Obtener el número de elementos en el diccionario
num_elementos = len(diccionario)
print(f'Número de elementos: {num_elementos}')

# Eliminar un elemento del diccionario
del diccionario['clave1']

# Iterar sobre las claves y valores del diccionario
for clave, valor in diccionario.items():
    print(f'Clave: {clave}, Valor: {valor}')
