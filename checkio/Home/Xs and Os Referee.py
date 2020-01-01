def checkio(game_result):
    for i in range(4):
        for row in game_result:
            if row[0] == row[1] == row[2] and row[0] != '.':
                return row[0]
        game_result = zip(*game_result)
    if game_result[0][0] == game_result[1][1] == game_result[2][2] and game_result[0][0] != '.':
        return game_result[0][0]
    if game_result[0][2] == game_result[1][1] == game_result[2][0] and game_result[1][1] != '.':
        return game_result[1][1]
    return 'D'
    
