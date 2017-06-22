/*
 * see_pcl_pointcloud.cpp
 *
 *  Created on: 2017年6月20日
 *      Author: tbm
 */

#include <iostream> //标准输入输出流
#include <pcl/io/pcd_io.h> //PCL的PCD格式文件的输入输出头文件
#include <pcl/point_types.h> //PCL对各种格式的点的支持头文件
#include <pcl/visualization/cloud_viewer.h>
#include <ros/ros.h>


int main(int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>); // 创建点云（指针）

    if (pcl::io::loadPCDFile<pcl::PointXYZ>("/tmp/local_map.pcd", *cloud) == -1) //* 读入PCD格式的文件，如果文件不存在，返回-1
    {
        PCL_ERROR("Couldn't read file local_map.pcd \n"); //文件不存在时，返回错误，终止程序。
        return (-1);
    }

    std::cout << "cloud width =  " << cloud->width << "\n cloud height = " <<cloud->height << std::endl;
    std::cout << std::endl;


    //for (size_t i = 0; i < cloud->points.size (); ++i) //显示所有的点
    for (size_t i = 0; i < cloud->size(); ++i) // 为了方便观察，只显示前5个点
        std::cout << "    " << cloud->points[i].x
        << " " << cloud->points[i].y
        << " " << cloud->points[i].z << std::endl;

    pcl::visualization::CloudViewer viewer("pcd viewer");
    pcl::PCLPointCloud2 pcl_point_cloud_2;
     pcl::toPCLPointCloud2(*cloud, pcl_point_cloud_2);
     //pcl::io::saveVTKFile("/tmp/local_map.vtk", pcl_point_cloud_2);
     //pcl::io::
    viewer.showCloud(cloud);
    ros::spin();
    //system("pause");
    return (0);
}


