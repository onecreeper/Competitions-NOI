import requests
import os
from bs4 import BeautifulSoup
from urllib.parse import urlparse

def download_file(url, filepath):
    """下载文件并保存到指定路径"""
    try:
        response = requests.get(url)
        response.raise_for_status()
        os.makedirs(os.path.dirname(filepath), exist_ok=True)
        with open(filepath, 'wb') as f:
            f.write(response.content)
        return True
    except Exception as e:
        print(f"下载失败: {e}")
        return False

def get_cpp_exams(html_content):
    """从HTML内容中提取所有C++题目下载链接及其名字"""
    soup = BeautifulSoup(html_content, 'html.parser')
    cpp_exams = []
    
    # 查找所有包含C++的链接
    for p in soup.select('.detailsP p'):
        a_tag = p.find('a')
        if a_tag and 'C++' in a_tag.get('title', ''):
            cpp_exams.append({
                'name': a_tag['title'],
                'url': a_tag['href']
            })
    return cpp_exams

def get_gesp_exams():
    """获取所有GESP认证真题及其链接"""
    url = 'https://gesp.ccf.org.cn/101/1010/index.html'
    
    try:
        # 获取网页内容
        response = requests.get(url)
        response.raise_for_status()  # 检查请求是否成功
        html_content = response.text

        # 解析HTML
        soup = BeautifulSoup(html_content, 'html.parser')
    except requests.exceptions.RequestException as e:
        print(f"获取网页内容失败: {e}")
        return {}

    # 查找所有真题
    results = {}
    for item in soup.select('.indexNoticeListItem'):
        title = item.select_one('main > div:first-child')
        date = item.select_one('main > div:last-child')
        link = item['href']
        
        if title and date and link:
            results[title.text.strip()] = {
                'date': date.text.strip(),
                'url': 'https://gesp.ccf.org.cn' + link
            }

    return results

def process_exam_page(url):
    """处理单个真题页面"""
    try:
        response = requests.get(url)
        response.raise_for_status()
        html_content = response.text
        cpp_exams = get_cpp_exams(html_content)
        
        for exam in cpp_exams:
            # 解析文件名
            name = exam['name']
            # 提取年份和月份
            year_month = name[:name.index('月')+1]  # 2023年9月
            # 提取等级
            level_start = name.find('C++') + 3
            level_end = name.find('真题')
            level = name[level_start:level_end].strip()  # 一级/二级/...
            
            # 创建目录
            dir_name = f"{year_month}GESP认证真题"
            filename = f"GESP {year_month}认证 C++{level}真题.pdf"
            filepath = os.path.join('downloads', dir_name, filename)
            
            # 下载文件
            print(f"正在下载: {exam['name']}")
            if download_file(exam['url'], filepath):
                print(f"已保存到: {filepath}")
            print()
    except Exception as e:
        print(f"处理页面 {url} 失败: {e}")

if __name__ == '__main__':
    # 获取所有真题页面
    exams = get_gesp_exams()
    
    # 处理每个真题页面
    for title, info in exams.items():
        if '真题' in title:  # 只处理包含"真题"的页面
            print(f"\n处理: {title}")
            process_exam_page(info['url'])
