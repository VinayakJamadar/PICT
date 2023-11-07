from PIL import Image, ImageChops

def calculate_ela(original_image_path, manipulated_image_path, scale=10):
    # Open the original and manipulated images
    original = Image.open(original_image_path)
    manipulated = Image.open(manipulated_image_path)

    # Resize the manipulated image to match the original's dimensions
    manipulated = manipulated.resize(original.size)

    # Calculate the ELA image
    ela_image = ImageChops.difference(original, manipulated)
    ela_image = ela_image.convert('L')
    ela_image = ela_image.point(lambda x: x * scale)

    return ela_image

def main():
    original_image_path = 'original.jpg'
    manipulated_image_path = 'manipulated.jpg'
    
    scale = 10  # Adjust the scale factor for the ELA image

    ela_image = calculate_ela(original_image_path, manipulated_image_path, scale)
    ela_image.show()
    ela_image.save('ela_image.jpg')

if __name__ == '__main__':
    main()