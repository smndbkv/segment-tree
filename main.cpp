#include "seg_tree.h"

int main(int argc, char **argv)
{
    int l = 0, r = 0, pos = 0;
    if (!(argc == 4 && sscanf(argv[1], "%d", &l) && sscanf(argv[2], "%d", &r) && sscanf(argv[3], "%d", &pos)))
    {
        printf("Usage: %s l r pos\n", argv[0]);
        return 0;
    }
    int a[] = {1, 2, 3, 4, 5};
    seg_tree<int> t1(a, 5);
    printf("%d\n", t1.get_sum(l, r));
    t1.update(pos, 100);
    printf("%d\n", t1.get_sum(l, r));

    std::string x[] = {"ab", "cd", "ef", "dh", "er"};
    seg_tree<std::string> t2(x, 5);
    std::cout << t2.get_sum(l, r) << std::endl;
    t2.update(pos, "xyz");
    std::cout << t2.get_sum(l, r) << std::endl;

    return 0;
}