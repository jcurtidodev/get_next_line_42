# 📜 Get Next Line

## 📌 Descripción
**Get Next Line** es una función que permite leer un archivo línea por línea de manera eficiente.
Se encarga de gestionar la lectura y el almacenamiento de los datos hasta encontrar un salto de línea (`'\n'`) o el final del archivo.

## 🎯 Funcionalidades
✅ Lee archivos línea por línea, sin cargar todo el contenido en memoria.

✅ Utiliza un **buffer dinámico** para optimizar la lectura de archivos grandes.

✅ Compatible con cualquier descriptor de archivo (archivos, `stdin`, sockets, etc.).

✅ Implementa un **stash (almacenamiento temporal)** para manejar fragmentos de línea leídos en múltiples llamadas.

✅ Manejo adecuado de errores y asignación de memoria.

## 📦 Archivos

📂 get_next_line/
```
├── get_next_line.c        # Implementación principal de get_next_line
├── get_next_line_utils.c  # Funciones auxiliares
└── get_next_line.h        # Archivo de cabecera con prototipos y macros
```

## 📂 Explicación de Archivos

### 📜 get_next_line.c
- `get_next_line(int fd)` → Función principal que lee y devuelve la siguiente línea de un archivo.
- `split_get_line(char **stash)` → Extrae la línea completa del almacenamiento temporal (`stash`).
- `split_manage_stash(char **stash, char *buffer)` → Añade nuevos datos al `stash`.

### 📜 get_next_line_utils.c
- `ft_strlen(const char *str)` → Calcula la longitud de una cadena.
- `ft_strchr(const char *s, int c)` → Busca un carácter en una cadena.
- `ft_strjoin(const char *s1, const char *s2)` → Concatena dos cadenas dinámicamente.
- `ft_strdup(const char *s1)` → Duplica una cadena en memoria dinámica.
- `ft_substr(const char *s, unsigned int start, size_t len)` → Extrae una subcadena de otra cadena.

## 🚀 Uso
### 1️⃣ Incluiye el archivo de cabecera en tu código:
```C
#include "get_next_line.h"
```

### 2️⃣ Uso básico en un archivo C
```C
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("archivo.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 🔔 Importante  
La función `get_next_line` ya ha sido añadida a **libft**, por lo que puedes usarla directamente sin necesidad de incluir archivos adicionales.

## 📌 Consideraciones
- `BUFFER_SIZE` Puede definirse al compilar.
```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c.
```
- La función **gestiona y libera correctamente la memoria** cuando es necesario.
- Si `read()` devuelve `0`, significa que se ha llegado al final del archivo.

## 🏆 Reglas y Restricciones
⚠️ **El proyecto debe cumplir:**
- Solo se pueden usar `read`, `malloc`, `free`.
- No está permitido `lseek` para volver atrás en la lectura.
- La función debe ser capaz de manejar múltiples descriptores de archivo simultáneamente.

## 🤝 Créditos
Proyecto desarrollado por `jcurtidodev` como parte del cursus de **42 School**.

