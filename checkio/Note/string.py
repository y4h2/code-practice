# remove punctuation
# this method is quicker than replace, but it can not replace punctuation as space
import string
exclude = set(string.punctuation)
text = ''.join(ch for ch in text if ch not in exclude).upper()
# replace space
import string
exclude = set(string.punctuation)
for c in exclude:
  if c in text:
    text = text.replace(c, ' ')
