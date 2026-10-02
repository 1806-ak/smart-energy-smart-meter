#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

int main() {
    const char* device = "/dev/smart_meter_pulse";

    int fd = open(device, O_RDWR);

    if (fd < 0) {
        std::cerr << "Failed to open " << device << std::endl;
        return 1;
    }

    const char pulse[] = "1";

    if (write(fd, pulse, 1) < 0) {
        std::cerr << "Failed to send pulse" << std::endl;
        close(fd);
        return 1;
    }

    char buffer[64] = {0};

    lseek(fd, 0, SEEK_SET);

    ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);

    if (bytes > 0) {
        buffer[bytes] = '\0';
        std::cout << "Driver pulse count: " << buffer;
    }

    close(fd);
    return 0;
}
