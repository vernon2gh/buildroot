SYSCALL_VERSION = 20200623
SYSCALL_SITE = $(TOPDIR)/localcode/syscall
SYSCALL_SITE_METHOD = local

define SYSCALL_BUILD_CMDS
    $(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D) all
endef

define SYSCALL_INSTALL_TARGET_CMDS
    $(MAKE) -C $(@D) install
endef

$(eval $(generic-package))
