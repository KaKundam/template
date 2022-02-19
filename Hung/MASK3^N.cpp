// i la con cua mask
// mask & i = i

for (int mask = 0; mask < (1<<n); mask++)
    for(int i = mask; i > 0; i = (i-1) & mask)