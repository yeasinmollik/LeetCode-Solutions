1. Find total number of connected-components(c) of the graph. The minimum number of edges needed to connect them is  $c - 1$.
2. For each connected component find the number of extra unncecessery edges. If a connected component has $n$ nodes and $e$ number of edges. Total extra nodes for this connected component is  $e - n + 1$. Add up the extra edges of  all connected components. Lets call it $extra$. 
3. Finally, if $extra$ is greater than or equal to $c - 1$, return $c - 1$; return **-1** otherwise.
