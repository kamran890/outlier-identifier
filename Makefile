OBJFILES = tests/test.o src/outlier_calculator.o
TARGET = test
CFLAGS = -I./include

.PHONY : all
All : $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(TARGET)

.PHONY: clean

clean:
	rm -f src/*.o test
