# Copyright (c) E5R Development Team. All rights reserved.
# Licensed under the Apache License, Version 2.0. More license information in LICENSE.txt.

CC=cl.exe
CC_FLAGS=/nologo
RM=del /F /Q
TARGET=hello.exe
SOURCES=main.c utils.c

$(TARGET): $(SOURCES)
	$(CC) $(CC_FLAGS) /Fe$(TARGET) $(SOURCES)

clean:
	$(RM) $(TARGET)
	$(RM) *.obj

all: $(TARGET)
