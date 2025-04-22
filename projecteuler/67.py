def main():
    triangle = list()
    read_file = open("0067_triangle.txt", "r")
    for line in read_file:
        triangle.append([int(x) for x in line.split()])
    read_file.close()


    for i in range(len(triangle)-2, -1, -1):
        for j in range(len(triangle[i])):
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1])

    print(triangle[0][0])












if __name__ == "__main__":
    main()





