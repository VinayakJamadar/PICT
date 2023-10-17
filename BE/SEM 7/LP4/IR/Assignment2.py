import numpy as np

# Sample graph represented as an adjacency matrix
# Each row represents a webpage, and each column represents links to other webpages.
# For example, A links to B and C, and so on.
adjacency_matrix = np.array([
    [0, 1, 1, 0],
    [1, 0, 0, 1],
    [1, 1, 0, 0],
    [0, 0, 1, 0]
], dtype=float)

# Initialize the Page Rank vector
num_pages = adjacency_matrix.shape[0]
pagerank = np.ones(num_pages) / num_pages

# Page Rank algorithm parameters
damping_factor = 0.85  # Typically set between 0.85 and 0.95
num_iterations = 100

# Perform the Page Rank calculation
for _ in range(num_iterations):
    new_pagerank = (1 - damping_factor) / num_pages + damping_factor * np.dot(adjacency_matrix.T, pagerank)
    pagerank = new_pagerank

# Display the Page Rank scores
print("Page Rank Scores:")
for i, score in enumerate(pagerank):
    print(f"Page {chr(65 + i)}: {score:.4f}")
