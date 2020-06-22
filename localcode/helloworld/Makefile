all : helloworld

helloworld :
	$(TARGET_CROSS)gcc helloworld.c -o helloworld

install :
	install -D -m 0755 helloworld $(TARGET_DIR)/usr/bin
