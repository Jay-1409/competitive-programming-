import openai
import openai

# Set your OpenAI GPT-3 API key
openai.api_key = 'api-key'

# Example prompt
prompt = "Translate the following English text to French:"

# Specify the model and parameters
response = openai.Completion.create(
  engine="text-davinci-002",  # Choose the engine that suits your needs
  prompt=prompt,
  max_tokens=100  # You can adjust this parameter based on your requirements
)

# Get the generated response
generated_text = response.choices[0].text

# Print or use the generated text
print(generated_text)


