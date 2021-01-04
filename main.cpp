#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv) {

    const char *shortOptions = "hvl:";

    static struct option longOptions[] = {
        {"help",    no_argument,       0, 'h'}, 
        {"version", no_argument,       0, 'v'},
        {"list",    required_argument, 0, 'l'},
        {"name",    no_argument, 0, 'n'},
        {0, 0, 0, 0},
    };

    const char *helpOption = "Program options:\n"
    "-h or --help                          - messages with program options\n"
    "-v or --version                       - current version of file\n"
    "-n or --name                          - current file name\n"
    "-l[<val1>,...]                        - list of available arguments\n";
    

    bool h_visited, v_visited, l_visited = false;
    
    int index, code;

    while ((code = getopt_long(argc, argv, shortOptions, longOptions, &index)) != -1) {
        switch (code) {
            case 'h': {
                if (!h_visited) {
                    h_visited = true;
                    printf("%s\n", helpOption);
                }
                break;
            }
            case 'l': {
                if (!l_visited) {
                    char *args;
                    printf("Option list:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL) {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    l_visited = true;
                }
                break;
            }
            case 'v': {
                if (!v_visited) {
                    v_visited = true;
                    printf("Current version\n");
                }
                break;
            }
            default: {
                printf("Error!\n");
                return 0;
            }
        }
    }
    return 0;
}
