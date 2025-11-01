import json
import requests
import zipfile
import io
import os

TEMPLATE_URL = "https://github.com/yoonoomilk/ps/archive/refs/heads/main.zip"
OUTPUT_FILE = "./.vscode/ps-template.code-snippets"

snippets = {}

response = requests.get(TEMPLATE_URL)
response.raise_for_status()

with zipfile.ZipFile(io.BytesIO(response.content)) as z:
  files = z.namelist()
  for file in files:
    if file.endswith(".cpp") and file.startswith("ps-main/template/"):
      with z.open(file) as f:
        content = f.read()
      body = [i.decode("utf-8") for i in content.splitlines()]
      name = os.path.basename(file)[:-4]
      snippets[name] = {
        "prefix": f"ps-{name}",
        "body": body,
        "description": f"{name} template",
        "scope" : "cpp"
      }

with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
  json.dump(snippets, f, indent=2, ensure_ascii=False)

print(f"saved {len(snippets)} templates")