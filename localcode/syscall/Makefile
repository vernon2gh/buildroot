all : syscall

syscall :
	$(TARGET_CROSS)gcc syscall.c -o syscall

install :
	install -D -m 0755 syscall $(TARGET_DIR)/usr/bin
