from sklearn.metrics.pairwise import cosine_similarity
from sklearn.feature_extraction.text import CountVectorizer

document1 = "The quick brown fox jumps over the lazy dog."
document2 = "A fast, brown fox leaps over the sleepy dog."

documents = [document1, document2]

vectorizer = CountVectorizer()

X = vectorizer.fit_transform(documents)
print(X)
cosine_sim = cosine_similarity(X)

print("Cosine Similarity Matrix:")
print(cosine_sim)

similarity_doc1_doc2 = cosine_sim[0][1]
print(f"Similarity between document 1 and document 2: {similarity_doc1_doc2:.2f}")
