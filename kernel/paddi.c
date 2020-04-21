#include <linux/init.h>
#include <linux/kobject.h>
#include <linux/module.h>
#include <linux/stat.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <uapi/linux/stat.h>
#define STR_SIZE_MAX	4

static int str_size;
static char str_tmp[STR_SIZE_MAX];

static ssize_t paddi_show(struct kobject *kobj,
			  struct kobj_attribute *attr,
			  char *buff)
{
	strncpy(buff, str_tmp, str_size);
	return str_size;
}

static ssize_t paddi_store(struct  kobject *kobj,
			   struct kobj_attribute *attr,
			   const char *buff, size_t count)
{
	str_size = min(count, (size_t)STR_SIZE_MAX);
	strncpy(str_tmp, buff, str_size);
	asm volatile (".quad 0x060200003aa00000");
	return count;
}

static struct kobj_attribute paddi_attribute =
	__ATTR(foo, S_IRUGO | S_IWUSR, paddi_show, paddi_store);

static struct attribute *attrs[] = {
	&paddi_attribute.attr,
	NULL,
};

static struct attribute_group attr_group = {
	.attrs = attrs,
};

static struct kobject *kobj;

static int __init myinit(void)
{
	int ret;

	kobj = kobject_create_and_add("paddi_invoke", kernel_kobj);
	if (!kobj)
		return -ENOMEM;
	ret = sysfs_create_group(kobj, &attr_group);
	if (ret)
		kobject_put(kobj);
	return ret;
}

late_initcall(myinit);
