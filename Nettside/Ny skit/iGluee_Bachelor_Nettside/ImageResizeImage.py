from PIL import Image
import os

# Konfigurasjon for ønsket størrelse
TARGET_SIZE = (300, 300)  # Bredde x Høyde
INPUT_FOLDER = "Bilder"  # Mappen der originalbildene ligger
OUTPUT_FOLDER = "optimized_images"  # Mappen for de optimaliserte bildene

# Sørg for at output-mappen eksisterer
os.makedirs(OUTPUT_FOLDER, exist_ok=True)

def resize_images():
    # Gå gjennom alle filer i input-mappen
    for filename in os.listdir(INPUT_FOLDER):
        if filename.lower().endswith(('.png', '.jpg', '.jpeg')):  # Sjekk om filen er et bilde
            img_path = os.path.join(INPUT_FOLDER, filename)
            with Image.open(img_path) as img:
                # Sjekk bildestørrelse
                if img.size != TARGET_SIZE:
                    print(f"Resizing {filename} (Original size: {img.size})...")
                    # Endre størrelse på bildet
                    resized_img = img.resize(TARGET_SIZE, Image.Resampling.LANCZOS)  # Oppdatert her
                    output_path = os.path.join(OUTPUT_FOLDER, filename)
                    # Lagre det optimaliserte bildet
                    resized_img.save(output_path)
                else:
                    print(f"{filename} er allerede i riktig størrelse.")
                    # Kopier bildet til output-mappen uten endringer
                    img.save(os.path.join(OUTPUT_FOLDER, filename))

if __name__ == "__main__":
    print("Starter prosessering av bilder...")
    resize_images()
    print("Ferdig! Sjekk mappen 'optimized_images' for de nye bildene.")
