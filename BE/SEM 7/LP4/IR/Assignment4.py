from functools import reduce

# Sample dataset
dataset = """
This is a sample dataset.
It contains both uppercase and lowercase letters.
The count should be case-insensitive.
"""

# Mapper function to tokenize and filter out non-alphabetic characters
def mapper(text):
    filtered_text = filter(str.isalpha, text.lower())
    return "".join(filtered_text)

# Reducer function to count occurrences
def reducer(counts, char):
    counts[char] = counts.get(char, 0) + 1
    return counts

# Map step: Apply the mapper function to the dataset
mapped_data = map(mapper, dataset)

# Reduce step: Apply the reducer function to get the character counts
character_counts = reduce(reducer, "".join(mapped_data), {})

# Sort the results by character for a more readable output
sorted_character_counts = {k: character_counts[k] for k in sorted(character_counts)}

# Print the results
for char, count in sorted_character_counts.items():
    print(f"{char}: {count}")
