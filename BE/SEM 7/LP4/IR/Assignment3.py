import nltk
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
import spacy

nltk.download('punkt')
nltk.download('stopwords')
nlp = spacy.load("en_core_web_sm")

# Sample text document
text = "The cats are playing in the gardens."

# Tokenization and stop word removal (NLTK)
words = nltk.word_tokenize(text)
stop_words = set(stopwords.words('english'))
filtered_words = [word for word in words if word.lower() not in stop_words]

# Tokenization, lemmatization, and stemming (spaCy and NLTK)
doc = nlp(text)
lemmatized_words = [token.lemma_ for token in doc]
stemmer = PorterStemmer()
stemmed_words = [stemmer.stem(word) for word in words]

print("Original Text:")
print(text)

print("\nTokenization and Stop Word Removal (NLTK):")
print(filtered_words)

print("\nLemmatization (spaCy):")
print(lemmatized_words)

print("\nStemming (NLTK):")
print(stemmed_words)
