# Introduction

This folder contains the CUDA implementation of GAT. It only contains one GAT layer. It is benchmarked using different datasets including Cora, PubMed, and randomly generated graphs.

# Experiments

#### TILE_WIDTH=32

```
cora 
nnz: 13264, #feats: 1433, #nodes: 2708
pubmed
nnz: 108365, #feats: 500, #nodes: 19717
```



##### #heads=8, #msgs=64

|         | Cora           | PubMed          |
| ------- | -------------- | --------------- |
| Seq     | 9854.37 (3.21) | 25225.43 (6.58) |
| CUDA    | 147.38 (3.83)  | 292.96 (4.57)   |
| Speedup | 66.86x         | 98.11x          |



##### #nodes = 400, #feats = 1433, #heads=8, #msgs=64

Each column is a different graph density.

|         | 1e-2           | 1e-1           | 3e-1           |
| ------- | -------------- | -------------- | -------------- |
| Seq     | 1456.28 (1.77) | 1490.41 (1.39) | 1565.20 (0.30) |
| CUDA    | 74.64 (0.66)   | 81.00 (3.00)   | 74.74 (0.42)   |
| Speedup | 19.51x         | 18.40x         | 20.94x         |



##### #nodes = 1200, #feats = 1433, #heads=8, #msgs=64

Each column is a different graph density.

|         | 1e-2           | 1e-1           | 3e-1            |
| ------- | -------------- | -------------- | --------------- |
| Seq     | 4390.29 (2.93) | 4702.63 (0.53) | 5409.46 (17.87) |
| CUDA    | 110.44 (2.79)  | 111.38 (4.32)  | 113.19 (3.24)   |
| Speedup | 39.75x         | 42.22x         | 47.79x          |



##### #nodes = 5000, #feats = 1433, #heads=8, #msgs=64

Each column is a different graph density.

|         | 1e-2             | 1e-1               | 3e-1              |
| ------- | ---------------- | ------------------ | ----------------- |
| Seq     | 18734.43 (61.71) | 25116.16 (1640.34) | 37327.55 (929.92) |
| CUDA    | 222.57 (2.65)    | 233.73 (0.31)      | 288.29 (5.72)     |
| Speedup | 84.17x           | 107.46x            | 129.48x           |



##### #nodes = 1200, #feats = 50, #heads=8, #msgs=64

Each column is a different graph density.

|         | 1e-2          | 1e-1          | 3e-1           |
| ------- | ------------- | ------------- | -------------- |
| Seq     | 190.58 (0.69) | 505.57 (0.75) | 1200.27 (1.74) |
| CUDA    | 61.03 (2.16)  | 62.93 (3.64)  | 64.32 (2.85)   |
| Speedup | 3.12x         | 8.03x         | 18.66x         |



##### #nodes=5000, #heads=8, #msgs=64, density=1e-1

| Total  | mm_kernel | heat_kernel | attn_kernel | aggregate_kernel |
| ------ | --------- | ----------- | ----------- | ---------------- |
| 275.53 | 183.28    | 0.08        | 7.41        | 6.72             |

