# lineeditor.c
# Simple Line Editor in C

A command-line text editor written in C that allows users to create, view, insert, and delete lines of text directly from the terminal.

## Features

- Insert a new line at a specific line number
- Delete a line using its line number
- Display the complete document with line numbers
- Handles empty documents
- Handles invalid line numbers
- Simple menu-based command-line interface

## Data Structure

The project uses an **array of strings** to store the document.

```c
char lines[100][200];