# Created by: <ports@FreeBSD.org>
# $FreeBSD$

PORTNAME=	simple-obfs
PORTVERSION=	0.0.3
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple obfuscating tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsodium.so:security/libsodium \
		libev.so:devel/libev \
		libudns.so:dns/udns

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes
DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
DOCS_CONFIGURE_OFF=   --disable-documentation

USE_GITHUB=	yes
GH_ACCOUNT=	shadowsocks
GH_PROJECT=	simple-obfs
GH_TAGNAME=	ace8bd2
GH_TUPLE+=	shadowsocks:libcork:3bcb832:libcork

GNU_CONFIGURE=	yes
USES=		gmake autoreconf libtool:keepla localbase pathfix
CFLAGS+=	-fstack-protector

post-extract:
	@${RMDIR} ${WRKSRC}/libcork
	@${MV} ${WRKSRC_libcork} ${WRKSRC}/libcork

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh)

.include <bsd.port.mk>
