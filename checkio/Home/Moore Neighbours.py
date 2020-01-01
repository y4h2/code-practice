def count_neighbours(grid, row, col):
    neighbour = ((-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1))
    count = 0
    for shift in neighbour:
        n_row = row + shift[0]
        n_col = col + shift[1]
        if (n_row >= 0 and n_row < len(grid)) and (n_col >= 0 and n_col < len(grid[0])):
            count += grid[n_row][n_col]
            
    return count
