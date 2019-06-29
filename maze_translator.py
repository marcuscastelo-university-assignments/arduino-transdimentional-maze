vec = []
vec.append("+]+-+-+-+-+-+-+-+-+-+-+")
vec.append("|         |     |     |")
vec.append("+-+ +-+-+ +-+ + + +-+-+")
vec.append("|   |         | |     |")
vec.append("+ +-+ +-+ +-+-+ +-+ + +")
vec.append("| |     | |   |   | | |")
vec.append("+ + +-+-+ + + +-+ +-+ +")
vec.append("| |   |   | |     |   |")
vec.append("+ +-+ + +-+-+-+ +-+ + +")
vec.append("| |   |       |     | |")
vec.append("+ +-+-+-+-+-+ +-+-+-+ +")
vec.append("| |   |       |   |   |")
vec.append("+ + + + +-+-+-+ + + +-+")
vec.append("|   |   |   |   | |   |")
vec.append("+-+-+-+-+ +-+ + +-+-+ +")
vec.append("|             |    [  |")
vec.append("+-+-+-+-+-+-+-+-+-+-+-+")

vect=[[vec[i][j] for j in range(len(vec[i]))] for i in range(len(vec))]




for i in range(len(vect)):
	for j in range(len(vect[i])):
		if vect[i][j] == '[':
			vect[i][j] = 4
		elif vect[i][j] == ']':
			vect[i][j] = 5 
		elif vect[i][j] == '+':
			vect[i][j] = 2
		elif vect[i][j] == '|' or vect[i][j] == '-':
			vect[i][j] = 1
		elif i % 2 == 0:
			vect[i][j] = 0
		else:
			if j % 2 == 0:
				vect[i][j] = 0
			else:
				vect[i][j] = 3

	print(vect[i])



