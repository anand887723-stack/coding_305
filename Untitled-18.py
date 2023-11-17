def generate_bigrams(text):
    bigram_dict = {}

    # Remove spaces and convert to lowercase
    text = text.replace(" ", "").lower()

    for i in range(len(text) - 1):
        bigram = text[i:i + 2]
        if bigram in bigram_dict:
            bigram_dict[bigram] += 1
        else:
            bigram_dict[bigram] = 1

    return bigram_dict


def feature_vector(text):
    bigram_dict = generate_bigrams(text)
    sorted_bigrams = sorted(bigram_dict.keys())
    feature_vector = {}

    for bigram in sorted_bigrams:
        utf8_value = bigram.encode('utf-8').hex()
        decimal_value = int(utf8_value, 16)
        feature_vector[decimal_value] = bigram_dict[bigram]

    return feature_vector


# Test case
input_string = "do or do not"
input_string2 = "banana"
result = feature_vector(input_string)
output = ' '.join([f"{k}:{v}" for k, v in sorted(result.items())])
print(f"Feature Vector ('{input_string}') = {output}")


result = feature_vector(input_string2)
output = ' '.join([f"{k}:{v}" for k, v in sorted(result.items())])
print(f"Feature Vector ('{input_string2}') = {output}")
