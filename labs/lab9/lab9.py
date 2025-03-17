from PIL import Image, ImageEnhance
import os

def gif_to_images(gif_path: str, output_dir: str):
    try:
        os.makedirs(output_dir, exist_ok=True)
        with Image.open(gif_path) as img:
            for frame in range(img.n_frames):
                img.seek(frame)
                img.save(f"{output_dir}/frame_{frame}.png")
    except FileNotFoundError:
        return "GIF file not found"

def read_file(file_path: str) -> Image:
    try:
        img = Image.open(file_path)
        return img
    except FileNotFoundError:
        return "error"
    
def adjust_img_brightness(file_path: str, output_path: str, brightness_factor: float):
    try:
        img = read_file(file_path).convert('RGB')
        enhancer = ImageEnhance.Brightness(img)
        img_enhanced = enhancer.enhance(brightness_factor)
        img_enhanced.save(output_path)

    except FileNotFoundError:
        return "Image file not found"
    
def adjust_img_brightness_series(input_dir: str, output_dir: str):
    try:
        os.makedirs(output_dir, exist_ok=True)
        for file_name in os.listdir(input_dir):
            file_path = os.path.join(input_dir, file_name)
            img = read_file(file_path).convert('RGB')
            enhancer = ImageEnhance.Brightness(img)
            img_enhanced = enhancer.enhance(1.5)  # Example brightness factor
            output_path = os.path.join(output_dir, file_name)
            img_enhanced.save(output_path)
    except FileNotFoundError:
        return "Image file not found"
    
def create_gif_from_frames(output_dir: str, output_gif_name: str, duration: int):
    frames = []
    
    for i in range(len(os.listdir(output_dir))):
        frame_path = os.path.join(output_dir, f"frame_{i}.png")
        frame = Image.open(frame_path)
        frames.append(frame)
    
    if frames:
        output_gif_path = os.path.join(output_dir, f"{output_gif_name}.gif")
        frames[0].save(output_gif_path, save_all=True, append_images=frames[1:], duration=duration, loop=0)
    else:
        return "No frames to save"

if __name__ == '__main__':
    print(gif_to_images('gif_asset/aisquaredv3.gif', 'input_assets'))
    print(adjust_img_brightness_series('input_assets', 'output_assets'))
    print(create_gif_from_frames('output_assets', "output_assets", int(1000/30))) # 30 fps