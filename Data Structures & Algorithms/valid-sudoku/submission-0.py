class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        digitCounter = [0] * 9
        #counterCondition = all(x in (0, 1) for x in digitCounter)

        #first count horizontal squares
        for j in range(9):
            for i in range(9):
                if board[j][i] == ".":
                    continue
                digitCounter[int(board[j][i]) - 1] += 1 #using -1 since the digits are 1-9
            if all(x in (0, 1) for x in digitCounter) == False:
                print("first block")
                return False
            digitCounter = [0] * len(digitCounter)

        #then count vertical squares
        for j in range(9):
            for i in range(9):
                if board[i][j] == ".":
                    continue
                digitCounter[int(board[i][j]) - 1] += 1 #using -1 since the digits are 1-9
            if all(x in (0, 1) for x in digitCounter) == False:
                print("middle block")
                return False
            digitCounter = [0] * len(digitCounter)

        #last count 3x3 boxes
        for i in range(3):
            #this will count the LEFT column of 3x3 boxes
            for j in range(3): 
                for k in range(3):
                    if board[j + i*3][k] == ".":
                        continue
                    digitCounter[int(board[j + i*3][k])-1] += 1
            if all(x in (0, 1) for x in digitCounter) == False:
                print("left column row ", i)
                return False
            digitCounter = [0] * len(digitCounter)

            #this will count the MIDDLE column of 3x3 boxes
            for j in range(3): 
                for k in range(3):
                    if board[j + i*3][k + 3] == ".":
                        continue
                    digitCounter[int(board[j + i*3][k + 3])-1] += 1
            if all(x in (0, 1) for x in digitCounter) == False:
                print("middle column row ", i)
                return False
            digitCounter = [0] * len(digitCounter)

             #this will count the MIDDLE column of 3x3 boxes
            for j in range(3): 
                for k in range(3):
                    if board[j + i*3][k + 6] == ".":
                        continue
                    digitCounter[int(board[j + i*3][k + 6])-1] += 1
            if all(x in (0, 1) for x in digitCounter) == False:
                print("middle column row ", i)   
                return False
            digitCounter = [0] * len(digitCounter)
            
        return True
