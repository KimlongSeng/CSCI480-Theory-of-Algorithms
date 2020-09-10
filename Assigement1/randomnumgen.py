import random

file1 = open("RanNum.txt", "a")
file2 = open("ForSortNum.txt", "a")
count =0
random.seed(700452202)

while (count<2000000):

    file1.writelines(str(random.randint(0,1000000000)))
    file1.write("\n")
    file2.writelines(str(random.randint(0,1000000000)))
    file2.write("\n")
    count =count +1


file1.close()