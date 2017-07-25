# Created by: <ports@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shadowsocks-libev
PORTVERSION=	20170721.195400
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libev port of shadowsocks

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsodium.so:security/libsodium \
		libev.so:devel/libev \
		libudns.so:dns/udns \
		libmbedcrypto.so:security/mbedtls \
		libpcre.so:devel/pcre

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes
DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
DOCS_CONFIGURE_OFF=	--disable-documentation

USE_GITHUB=	yes
GH_ACCOUNT=	shadowsocks
GH_PROJECT=	shadowsocks-libev
GH_TAGNAME=	bf8f831
GH_TUPLE+=	shadowsocks:libbloom:7a9deb8:libbloom
GH_TUPLE+=	shadowsocks:libcork:0220aa5:libcork
GH_TUPLE+=	shadowsocks:ipset:3ea7fe3:libipset

GNU_CONFIGURE=	yes
USES=		gmake libtool:keepla pathfix
CFLAGS+=	-fstack-protector
USE_RC_SUBR=	shadowsocks_libev

post-extract:
.for submodule in ${GH_TUPLE:C@^([^:]*):([^:]*):([^:]*):([^:/]*)@\4@}
	@${RMDIR} ${WRKSRC}/${submodule}
	@${MV} ${WRKSRC_${submodule}} ${WRKSRC}/${submodule}
.endfor

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh)

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${CP} ${WRKSRC}/debian/config.json  ${STAGEDIR}${ETCDIR}/config.json.sample

.include <bsd.port.mk>
