import random

file1 = open("RanNum.txt", "a")
count =0
random.seed(700452202)

while (count<100000):

    file1.writelines(str(random.randint(0,1000000000)))
    file1.write("\n")
    count =count +1


file1.close()