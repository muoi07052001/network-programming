#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Đề bài
 * Dùng lệnh system chạy lệnh "ls -a -l"
 * -> sau đó điều hướng ra file (ví dụ: ls.out).
 * Đọc file ls.out và phân tích để đưa ra danh sách các file (CHỈ CÓ FILE, KHÔNG CÓ THƯ MỤC) theo định dạng:
 * <Tên File 1> <Kích thước>
 * <Tên File 2> <Kích thước>
 * <Tên File 3> <Kích thước>
 * <Tên File 4> <Kích thước>
 * ..
 */

int main()
{
    system("ls -a -l > ls.out");

    FILE *f = fopen("ls.out", "rt");

    while (!feof(f))
    {
        char line[1024];
        memset(line, 0, sizeof(line));
        fgets(line, sizeof(line), f);

        if (line[0] == '-')
        {

            char permission[1024] = {0};
            char v1[1024] = {0};
            char owner[1024] = {0};
            char group[1024] = {0};
            char size[1024] = {0};
            char month[1024] = {0};
            char date[1024] = {0};
            char time[1024] = {0};
            char name[1024] = {0};

            sscanf(line, "%s%s%s%s%s%s%s%s%s", permission, v1, owner, group, size, month, date, time, name);
            while (name[strlen(name) - 1] == '\n' || name[strlen(name) - 1] == '\r')
            {
                name[strlen(name) - 1] = 0;
            }

            printf("%s %s\n", name, size);
        }
    }
}